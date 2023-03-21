这节可以学习的新东西好多，兴奋 ：）

# 效果
![效果图](images/1.png)
# 知识点
## FlexBox
参考：[阮一峰老师博客 -- Flex 布局教程：语法篇](https://www.ruanyifeng.com/blog/2015/07/flex-grammar.html)

网页布局（layout）是 CSS 的一个重点应用。

Flex布局是一种非常流行的布局解决方案。

终于解答了我之前看见style里面`display: flex;`和`flex: 1`的困惑了。直接看这篇博客就能解答大部分疑惑。

## 由代码中`> *`引起的困惑

下面这段代码知识点满满啊。

```css
.panel > *:first-child { transform: translateY(-100%); }
.panel.open-active > *:first-child { transform: translateY(0); }
.panel > *:last-child { transform: translateY(100%); }
.panel.open-active > *:last-child { transform: translateY(0); }
```
### `>`: 子元素选择器

`>`大于号的意思是 选择某元素后面的第一代子元素。
比如 `.panel > a`代表选择`class`为`panel`的元素下的第一代`a`元素。
### `*`: CSS通用选择器

参考：[通配选择器](https://developer.mozilla.org/zh-CN/docs/Web/CSS/Universal_selectors)

### `:`:伪类

参考：[伪类](https://developer.mozilla.org/zh-CN/docs/Web/CSS/Pseudo-classes)

CSS 伪类是添加到选择器的关键字，用于指定所选元素的特殊状态。例如，伪类 :hover 可以用于选择一个按钮，当用户的指针悬停在按钮上时，设置此按钮的样式。

相较于伪类，伪元素可用于设置元素特定部分的样式。

### `::`:伪元素

参考：[伪元素](https://developer.mozilla.org/zh-CN/docs/Web/CSS/Pseudo-elements)

伪元素是一个附加至选择器末的关键词，允许你对被选择元素的特定部分修改样式。下例中的 `::first-line` 伪元素可改变段落首行文字的样式。

```css
/* 每一个 <p> 元素的第一行。 */
p::first-line {
  color: blue;
  text-transform: uppercase;
}

```

### `.a.b 与 .a .b`
CSDN这样搜还真能搜到，哈哈。

参考： [css中.a.b 与 .a .b（中间有空格）的区别](https://blog.csdn.net/DZY_12/article/details/111991736)

区别：

> * .a.b是获取同时含有a和p的元素
> * .a .b（中间有空格），是获取.a元素下的所有.b元素
### 代码解释
```css
.panel > *:first-child { transform: translateY(-100%); }
.panel.open-active > *:first-child { transform: translateY(0); }
.panel > *:last-child { transform: translateY(100%); }
.panel.open-active > *:last-child { transform: translateY(0); }
```

第一行：选择类为`.panel`类下的所有子元素，对这些兄弟元素中的第一个元素，进行transform。

第一行：选择类既是`.panel`又是`.open-active`的所有子元素，对这些兄弟元素中的第一个元素，进行transform。

## 网页渲染
学到这里，我就有疑惑了。CSS又是怎么体现到网页上的呢？编译器？解释器？

既然有`DOM`，那是不是也有`COM`？

我又在阮一峰老师的博客上找到了清晰的答案: [网页性能管理详解](https://www.ruanyifeng.com/blog/2015/09/web-page-performance-in-depth.html)

> 网页的生成过程，大致可以分成五步。
> 1. HTML代码转化成DOM
> 2. CSS代码转化成CSSOM（CSS Object Model）
> 3. 结合DOM和CSSOM，生成一棵渲染树（包含每个节点的视觉信息）
> 4. 生成布局（layout），即将所有渲染树的所有节点进行平面合成
> 5. 将布局绘制（paint）在屏幕上

总体流程如下：
![](images/2.png)

这里又不得不提一下，JavaScript其实 共有=由三部分组成：
* ECMAScript
* BOM
* DOM

为什么没有CSSOM呢？CSSOM不是JS实现的？

## element.classList.toggle()
参考：
* https://developer.mozilla.org/zh-CN/docs/Web/API/Element/classList
* https://developer.mozilla.org/zh-CN/docs/Web/API/DOMTokenList/toggle
# 感谢
感谢本项目的作者💗，学到了好多东西。

特别鸣谢阮一峰老师，阮老师的技术博客在中文互联网中就是一股清流，一把瑞士军刀。