# 知识点

参考自：https://github.com/soyaine/JavaScript30/tree/master/03%20-%20CSS%20Variables

# HTML5 中的自定义数据属性 dataset
HTML5 中可以为元素添加非标准的自定义属性，只需要加上 data- 前缀，可以随便添加和命名。添加之后，可以通过元素的 dataset 属性来访问这些值，dataset 的值是 DOMStringMap 的一个实例化对象，其中包含之前所设定的自定义属性的“名-值”对。

## CSS variable
这是一个 CSS3 的新特性，IE 和 Edge 目前都还不支持。命名写法是 --变量名，在引用这个变量时写法是 var(--变量名)。具体实例见下一条代码。

## :root
CSS :root 伪类选择器匹配文档树的根元素。在 HTML 文档中，:root 表示 html 选择器， 除了CSS权重比它高以外，其他都是一样的。

```css
:root {
  background-color: blue;
}

html {
  background-color: yellow;
}
```

最终文档的背景色将会是 blue。

## this 指向释疑

这里事件处理函数`handleUpdate()`为什么指向input元素呢？

根据《你不知道的JavaScript上卷》p85的说法，这是**隐式绑定**的典型案例。

addEventListener()里添加的回调函数最后会在哪里调用呢？`element.invoke_function()`。本案例中对应的就是`input.handleUpdate()`。

这种情况下，

> 无论是直接在 obj 中定义还是先定义再添加为引用属性，这个函数严格来说都不属于 obj 对象。
> 
> 然而，调用位置会使用 obj 上下文来引用函数，因此你可以说函数被调用时 obj 对象“拥 有”或者“包含”它。
> 
> 无论你如何称呼这个模式，当 foo() 被调用时，它的落脚点确实指向 obj 对象。当函数引 用有上下文对象时，隐式绑定规则会把函数调用中的 this 绑定到这上下文对象。因为调 用 foo() 时 this 被绑定到 obj，因此 this.a 和 obj.a 是一样的。

这与《JavaScript高级程序设计》中的：

> 在标准函数中，this 引用的是把函数当成方法调用的上下文对象，这时候通常称其为 this 值(在 网页的全局上下文中调用函数时，this 指向 windows)。
> 
> 这个 this 到底引用哪个对象必须到 函数被调用时才能确定。
> 
> 在箭头函数中，this 引用的是定义箭头函数的上下文。

说法一致。
# 解决难点

如何处理参数值（一个有 px 、另一个没有）

运用 dataset 储存后缀，有 px 后缀的标签中设置  `<input data-sizing: px>`：

```html
<input type="range" name="blur" min="0" max="25" value="10" data-sizing="px">
<input type="color" name="base" value="#8aa8af">
```
JS 中通过 dataset.sizing 来获取后缀值：
```js
const suffix = this.dataset.sizing || ''; 
```
此时 suffix 获取到的值，针对颜色为空，而针对长度类的则为 'px'。

