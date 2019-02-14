#include <gtk/gtk.h>
#include <stdio.h>
#include <openssl/sha.h>

GtkWidget 	*window,\
		*aboutwindow,\
		*openmenu,\
		*savemenu,\
		*aboutmenu,\
		*textpasswd,\
		*texthash,\
		*do_hashbutton,\
		*do_checkbutton,\
		*label,\
		*tray,\
		*quit;




int main(int argc, char** argv)
{
	GtkBuilder      *builder; 
	guint		gtkret;

        gtk_init(&argc, &argv);
	builder = gtk_builder_new();
	gtkret = gtk_builder_add_from_file(builder,"sca.glade",NULL);
	if (!gtkret)
	{
		fprintf(stderr,"Error while creating object\n");
		return 1;
	}

	window 		= GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	openmenu 	= GTK_WIDGET(gtk_builder_get_object(builder, "openmenu"));
	savemenu 	= GTK_WIDGET(gtk_builder_get_object(builder, "savemenu"));
	aboutmenu	= GTK_WIDGET(gtk_builder_get_object(builder, "about"));
	textpasswd	= GTK_WIDGET(gtk_builder_get_object(builder, "TextPasswd"));
	texthash	= GTK_WIDGET(gtk_builder_get_object(builder, "TextHash"));
	do_hashbutton	= GTK_WIDGET(gtk_builder_get_object(builder, "hashbutton"));
	do_checkbutton	= GTK_WIDGET(gtk_builder_get_object(builder, "checkbutton"));
	label		= GTK_WIDGET(gtk_builder_get_object(builder, "statuslabel"));
	quit		= GTK_WIDGET(gtk_builder_get_object(builder, "quit"));
	tray		= GTK_WIDGET(gtk_builder_get_object(builder, "trayicon"));
	aboutwindow	= GTK_WIDGET(gtk_builder_get_object(builder, "about_window"));


	gtk_builder_connect_signals(builder, NULL);
 
	g_object_unref(builder);
 	
	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_widget_show(window);
	gtk_widget_show(tray);                
	gtk_main();


	return 0;
}

void fixme(void)
{
	fprintf(stderr,"FIXME: This feature doesn\'t exist yet\n");
}

void hash_openfile(GtkWidget *widget, GtkWidget *data)
{
	fixme();
}

void hash_save(GtkWidget *widget, GtkWidget *data)
{
	fixme();
}

void show_about(GtkWidget *widget, GtkWidget *data)
{
	gtk_widget_show(aboutwindow);
}

void do_hash(GtkWidget *widget, GtkWidget *data)
{
	const gchar *thetext;
	unsigned char txtdigest[SHA256_DIGEST_LENGTH];
	char sha256string[SHA256_DIGEST_LENGTH*2+1];
	char *textbuffer;
	
	thetext = gtk_entry_get_text(GTK_ENTRY(data));
	SHA256((unsigned char*)&thetext, strlen(thetext), (unsigned char*)&txtdigest);
	
	for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
            sprintf(&sha256string[i*2], "%02x", (unsigned int)txtdigest[i]);
	
	textbuffer = g_strconcat("Status: ",thetext,NULL);
	gtk_entry_set_text(GTK_ENTRY(texthash),sha256string);
	gtk_label_set_text(GTK_LABEL(label),textbuffer);
	g_free(textbuffer);
}

void do_check(GtkWidget *widget, GtkWidget *data)
{
	fixme();
}

