# QtRibbonGUI

Qt的纽带风格界面实现（Office Ribbon风格）
![img1](https://github.com/liang1057/QtRibbonGUI/blob/master/img/1.png)

    之前有朋友已经做了360风格的自定义界面，非常棒，也帮助了不少开发的朋友。近期我也用Qt做了一些界面框架和风格方面的工作，主要是客户端软件采用的OfficeRibbion风格，给朋友们看一看多交流。代码和实现暂时没有提供到我的下载资源中，有兴趣的朋友请联系我或者等待一段时间。
    这样看，是不是还能眼前一亮的感觉？拿了一个初期的界面看一下。这是采用了Word配色相近的方案，整体比较低调。

![img2](https://github.com/liang1057/QtRibbonGUI/blob/master/img/2.png)

Office Ribbon for word - style

三种风格的切换也是很容易的。如果不考虑特殊的控件，只需要修改配色方案即可达到效果。

![img3](https://github.com/liang1057/QtRibbonGUI/blob/master/img/3.png)


简要说一下开发的过程：使用Qt的特性。界面重构了一个RibbonWidget（请自动忽略代码类图中的拼写错误）, 所有的功能集中在Mainwindow中显示，包含了上面看到的各种资源。 Ribbon的风格，则体现在三个主要的部分： 标题栏、菜单栏和工具栏。
构建了这三个以后，一定要体现“分组”的概念，这样才能尽显纽带的风采。

![img4](https://github.com/liang1057/QtRibbonGUI/blob/master/img/4.png)

跟传统的菜单式用户界面相比较，Ribbon方式则较好的解决了上述问题。Ribbon功能区包含一些用于创建、编辑和导出仪表板及其元素的上下文工具。它是一个收藏了命令按钮和图示的面板。它把命令组织成一组"标签"，每一组包含了相关的命令。每一个应用程序都有一个不同的标签组，展示了程序所提供的功能。在每个标签里，各种的相关的选项组合在一起。
    新式的Ribbon（特别是OFFICE2016之后），采用了扁平化界面设计，使得界面风格更加简洁统一，清晰自然又不失严谨。在专业软件的应用中，能够更好的突出主题，让用户在操作中不被繁杂的界面困扰，将精力集中在功能上而不是界面上。
————————————————

CSDN上的原文链接：https://blog.csdn.net/sdust_dx/article/details/78792476

如果您觉得本代码对您有帮助,请支持我的开发，谢谢

![img5](https://github.com/liang1057/QtRibbonGUI/blob/master/Qt5Project/bin/bin/zhifubao.png)
