# introduction
Here are custom-designed widgets based on qt. All widgets are stored in folder `widgets`

### browse widget
If you want to browse these widgets, just run `./make.sh` in root directory of this repository. If it works well, then you can just to select a widget to display.

### doc
If `make.sh` doesn't run normally, you can also get preview of widgets in directory `doc`.

### translation
```bash
# create or update .ts file
lupdate .  -ts translations/cn.ts
```
Compile the Translation File
```bash
lrelease translations/cn.ts -qm translations/cn.qm
```



# widgets

### angle_panel

### azimuth_panel

### bar

### battery

### editable_label

### info_label

### panel

### switcher_dual

### office style
Office 2016 style window.
https://github.com/liang1057/QtRibbonGUI/tree/master