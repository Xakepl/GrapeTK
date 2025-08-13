#include <stdlib.h>
#include <gtk/gtk.h>
//#include <SFML/Audio.hpp>


// ЗНАЧКИ ДЛЯ ПРОИГРЫВАТЕЛЯ (взято из стима)
// [  ▐▐   ] - пауза
// [   ►   ] - Play (первый вариант)
// [  ►►   ] - следующий трек
// [  ◄◄   ] - предыдущий трек
// [   ◼   ] - стоп (будет заюзано?)
// [  🔎   ] - Поиск (сканирование)

static void click_button(GtkButton *btn){
    g_print("Coming soon");
}
static void Music(){

}

static void m(GtkButton btn, gpointer data){
    GtkWidget* dialog;
    GtkWidget* label;
    GtkWidget* content;

    dialog = gtk_dialog_new_with_buttons("Hi", NULL, GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, NULL);
    content = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    label = gtk_label_new("Сыграть пока что барабульку? (у вас нет выбора)");
    gtk_container_add(GTK_CONTAINER(content), label);
    gtk_widget_show(label);

    gtk_dialog_run(GTK_DIALOG(dialog));
    g_signal_connect(dialog, "clicked", G_CALLBACK(Music), NULL);
    gtk_widget_destroy(dialog);


}

int main( int argc,char *argv[] )
{
    /* gtkwidget является типом хранения для виджетов */
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *play;


    /* этот вызов используется во всех gtk программмах. аргументы из командной строки
     *   разбираются и возвращаются в приложение. */
    gtk_init (&argc, &argv);

    /* создается новое окно */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    /* когда окну поступает "delete_event" сигнал (это делает
     * менеджер окон, обычно "close" опция в верхнем заголовке окна),
     * задаётся вопрос delete_event() функции, как обсуждалось выше.
     * данные поступают в функцию обратного вызова являясь
     * null и игнорируются. */
    //g_signal_connect (g_object (window), "delete_event", g_callback (delete_event), null);

    /* здесь мы соединяем "destroy" событие с обработчиком сигнала.
     * это делается вызовом gtk_widget_destroy() в окне,
     * или если возвращаем false в обратном вызове "delete_event". */
    //g_signal_connect (g_object (window), "destroy", g_callback (destroy), null);

    /* устанавливаем ширину окантовки окна */
    /* создаем новую кнопку с ярлыком "hello world". */
    button = gtk_button_new_with_label ("🔎");
    //("▐▐ ");
//    play = gtk_button_new_with_label("►");

    /* когда кнопка получит "clicked" сигнал, то вызовет
     * функцию hello() с null аргументом. функция hello()
     * определена выше. */


    /* помещаем кнопку внутрь окна */
    gtk_container_add (GTK_CONTAINER(window), button);
    //gtk_container_add (GTK_CONTAINER(window), play);

    g_signal_connect(button, "clicked", G_CALLBACK(m), NULL);
    /* последний этап, вывод кнопки на экран. */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show (button);
  //  gtk_widget_show (play);

    /* вывод на экран окна. */
    gtk_widget_show (window);

    /* все gtk приложения содержат gtk_main(). здесь заканчивается контроль
     * и происходит ожидание(нажатие клавиши или мышки) */
    gtk_main ();

    return 0;
}
