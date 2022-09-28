/*------------------------------------------------------------------------------
    Задача (38.5.) 2. Создание приложения для редактирования HTML-файла
--------------------------------------------------------------------------------
  Что нужно сделать
  Создайте приложение, в котором окно делится на две половины. В левой половине
можно редактировать HTML-документ, а в правой — видеть результат WebView.
    Можете использовать Qt Creator и Qt Designer, чтобы быстро добавить два
элемента: QPlainTextEdit для редактирования текста и QWebEngineView для
отображения результата. Необходимо, чтобы каждый из виджетов занимал равное
количество пространства по горизонтали и все по вертикали.
    1. Выделите оба виджета. Зажмите Ctrl и щёлкните сначала по одному из
виджетов, а затем по второму. Нажмите «Расположить по горизонтали» или Lay out
horizontally.
    2. Для каждого из виджетов найдите параметр Horizontal stretch и сделайте
его равным единице

    Можете выполнить те же действия без использования Qt Designer. Задайте
sizePolicy.
    Приложение должно реагировать на изменения текста слева, сразу полностью
перестраивая представление HTML-документа справа.

    Критерии оценки
    Приложение отображает одно окно, в котором есть два текстовых виджета.
Каждый виджет занимает свою половину экрана. Левый виджет содержит текстовое
представление HTML-документа. Правый виджет — нарисованную web-страницу.

    При изменении исходного кода страницы в левом виджете представление в
правом сразу меняется.

    Как отправить задание на проверку
    Необходимо отправить один файл в формате CPP и один файл CMakeLists.txt.
Также можно отправить архивированный проект в Qt Creator. Через форму ниже
отправьте ссылку на repl.it или CPP-файл с решением. При использовании
Qt Creator пришлите архив с проектом.
------------------------------------------------------------------------------*/
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QWebEngineView>

int main(int argc, char *argv[]) {

  QApplication a(argc, argv);

  auto *mainWindow = new QMainWindow(nullptr);
  auto *mainWidget = new QWidget(mainWindow);
  auto *hbox = new QHBoxLayout(mainWidget);
  auto *textEdit = new QPlainTextEdit;
  auto *webView = new QWebEngineView;

  mainWindow->setCentralWidget(mainWidget);
  mainWindow->setWindowTitle("HTML editor");

  hbox->addWidget(textEdit);
  hbox->addWidget(webView);

  QSizePolicy distributor(QSizePolicy::Preferred, QSizePolicy::Preferred);
  distributor.setHorizontalStretch(1);

  textEdit->setSizePolicy(distributor);
  webView->setSizePolicy(distributor);

  QObject::connect(textEdit, &QPlainTextEdit::textChanged,
                   [textEdit, webView]() {
    webView->setHtml(textEdit->toPlainText());
    });

    mainWindow->show();

    return QApplication::exec();
}
