#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my = new shor();
    ui->input->setText("Enter positive n <= 100");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_input_returnPressed()
{
    std::string s = ui->input->text().toStdString();
    for (auto x : s) if (!('0' <= x && x <= '9')) {
        ui->output->setText("Wrong input!");
        return;
    }
    int n = stoi(s);
    if (n < 1 || n > 100) {
        ui->output->setText("Wrong input!");
        return;
    }
    if (n == 1) {
        ui->output->setText("1 = 1");
        return;
    }
    vector<int> ans = my->calc(n);
    if (ans.empty()) return;
    if (ans[0] == -1) {
        ui->output->setText("Too hard :(");
        return;
    }
    QString text;
    for (int i=0;i<(int)ans.size();i++) {
        text += QString::number(ans[i]);
        if (i + 1 != (int)ans.size()) text += " * ";
        else text += " = ";
    }
    text += QString::number(n);
    ui->output->setText(text);
}

void MainWindow::printsmth()
{
    ui->output->setText("Test #1");
}

void MainWindow::printTries(int x) {
   // ui->test->append("\nTry #" + QString::number(x));
}
