
# add widgets to mainwindow

DIR_PATH="./widgets"

# Get all subdirectories
subdirs=$(find "$DIR_PATH" -mindepth 1 -maxdepth 1 -type d)

# traverse the names of the subdirectories and add them to mainwindow
cat <<EOF > "./src/add_widgets.cpp"
void MainWindow::addWidgets()
{
EOF
ind=0

cat <<EOF > "./widgets/widgets.h"
// all widgets are included
EOF

for subdir in $subdirs; do
  # echo $(basename "$subdir")
  name=$(basename "$subdir")
  Name=""
  # Internal Field Separator
  IFS='_' 
  # Convert string into an array
  read -ra PARTS <<< "$name"
  # Reset IFS if needed
  unset IFS
  for PART in "${PARTS[@]}"; do
    # echo "$PART"
    # Convert first character to uppercase
    Name=${Name}$(echo "$PART" | sed 's/./\U&/') 
  done
  # echo ${Name}
  # add current widget
  cat <<EOF >> "./src/add_widgets.cpp"
  {
    ui->comboBox->addItem(QString());
    ui->comboBox->setItemText(${ind}, QApplication::translate("MainWindow", "${name}", nullptr));
    QWidget* cur_widget;
    cur_widget=new ${Name}(this);
    cur_widget->move(100,100);
    widgets.push_back(cur_widget);
  }
EOF

  cat <<EOF >> "./widgets/widgets.h"
#include "./${name}/${name}.h"
EOF

  ind=$(echo "$ind + 1" | bc)

done


cat <<EOF >> "./src/add_widgets.cpp"
}
EOF



exit