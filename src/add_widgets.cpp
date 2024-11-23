void MainWindow::addWidgets()
{
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(0, QApplication::translate("MainWindow", "angle_panel", nullptr));
    QWidget* cur_widget;
    cur_widget=new AnglePanel(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(1, QApplication::translate("MainWindow", "azimuth_panel", nullptr));
    QWidget* cur_widget;
    cur_widget=new AzimuthPanel(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(2, QApplication::translate("MainWindow", "bar", nullptr));
    QWidget* cur_widget;
    cur_widget=new Bar(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(3, QApplication::translate("MainWindow", "battery", nullptr));
    QWidget* cur_widget;
    cur_widget=new Battery(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(4, QApplication::translate("MainWindow", "editable_label", nullptr));
    QWidget* cur_widget;
    cur_widget=new EditableLabel(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(5, QApplication::translate("MainWindow", "info_label", nullptr));
    QWidget* cur_widget;
    cur_widget=new InfoLabel(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(6, QApplication::translate("MainWindow", "panel", nullptr));
    QWidget* cur_widget;
    cur_widget=new Panel(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(7, QApplication::translate("MainWindow", "switcher_dual", nullptr));
    QWidget* cur_widget;
    cur_widget=new SwitcherDual(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(8, QApplication::translate("MainWindow", "title_bar", nullptr));
    QWidget* cur_widget;
    cur_widget=new TitleBar(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
}
