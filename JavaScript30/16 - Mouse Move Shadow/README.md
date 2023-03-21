# 知识点
## 解构赋值
参考：https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment

> 解构赋值语法是一种 Javascript 表达式。可以将数组中的值或对象的属性取出，赋值给其他变量。
>

```js
let a, b, rest;
[a, b] = [10, 20];
[a, b, ...rest] = [10, 20, 30, 40, 50];

const { a: a1, b: b1 } = obj;
// equals
a1 = obj.a
b1 = obj.b
```

## Event.target
> The read-only target property of the Event interface is a reference to the object onto which the event was dispatched. 

有点奇妙的，就是JS事件链里的知识点。
官网的例子：
```js
// Make a list
const ul = document.createElement("ul");
document.body.appendChild(ul);

const li1 = document.createElement("li");
const li2 = document.createElement("li");
ul.appendChild(li1);
ul.appendChild(li2);

function hide(evt) {
  // evt.target refers to the clicked <li> element
  // This is different than evt.currentTarget, which would refer to the parent <ul> in this context
  evt.target.style.visibility = "hidden";
}

// Attach the listener to the list
// It will fire when each <li> is clicked
ul.addEventListener("click", hide, false);

```

## style.textShadow

参考官网：https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow

> The text-shadow CSS property adds shadows to text. It accepts a comma-separated list of shadows to be applied to the text and any of its decorations. Each shadow is described by some combination of X and Y offsets from the element, blur radius, and color.

# 心得

要记住这么多属性啥的既不现实也不科学，这不是人擅长的工作。我觉得老师说的一句话很对：

> 设计上自顶向下，实现上自底向上。

我们现在只要清楚API很丰富就可以了。最重要的Idea(Not IDEA)。