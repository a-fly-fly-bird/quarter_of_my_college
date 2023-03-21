太干了🔥，又是干货满满的一集。

# 知识点
## Fetch API

参考教程：[Fetch API 教程](https://www.ruanyifeng.com/blog/2020/12/fetch-tutorial.html)

> fetch()是 XMLHttpRequest 的升级版，用于在 JavaScript 脚本里面发出 HTTP 请求。
> 
> 浏览器原生提供这个对象。
> 
这里就有必要先了解一下 XMLHttpRequest。

### XMLHttpRequest 和 Ajax
参考：
* https://zhuanlan.zhihu.com/p/163718536
* https://developer.mozilla.org/zh-CN/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest

AJAX = Asynchronous JavaScript and XML，翻译为：异步的 JavaScript 和 XML。ajax就是基于浏览器提供的XMLHttpRequest对象来实现的。

> 传统的网页（不使用 AJAX）如果需要更新内容，必需重载整个网页面。

Ajax在XMLHttpRequest的基础上提供了异步的特性。

### Fetch
* Fetch使用了Promise，也就是说支持异步，写法也更简洁了。
* > fetch()通过数据流（Stream 对象）处理数据，可以分块读取，有利于提高网站性能表现，减少内存占用，对于请求大文件或者网速慢的场景相当有用。XMLHTTPRequest 对象不支持数据流，所有的数据必须放在缓存里，不支持分块读取，必须等待全部拿到后，再一次性吐出来。

Fetch请求有两种写法：
* 第一种 then()
```js
  fetch(url)
  .then(...)
  .catch(...)
```
以及
* 使用async awiat 代替
```
async function(){
    await fetch()
}
```
对应到本次实践的代码中：

```js
// async function getData(endpoint){
//   const response = await fetch(endpoint);
//   const data = await response.json();
//   cities.push(...data);
// }

// 上下两种写法选一种

// fetch return promise
fetch(endpoint)
  .then(blob => 
  // console.log(blob);
  // JSON.parse(blob)
  blob.json())
  // .then(data => console.log(data));
  .then(data => cities.push(...data));
```

## JSON.parse(response) 和 response.json() 区别

参考：
* 上文阮一峰老师教程
* https://developer.mozilla.org/zh-CN/docs/Web/API/Response/json
  
JSON.parse() 是同步操作。

> fetch()接收到的response是一个 Stream 对象，response.json()是一个异步操作，取出所有内容，并将其转为 JSON 对象。

## JavaScript join() 方法

join() 方法用于把数组中的所有元素转换一个字符串。

元素是通过指定的分隔符进行分隔的。

参考：https://www.runoob.com/jsref/jsref-join.html

## `...`: 拓展运算符

参考： https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Spread_syntax

> 展开语法 (Spread syntax), 可以在函数调用/数组构造时，将数组表达式或者 string 在语法层面展开；还可以在构造字面量对象时，将对象表达式按 key-value 的方式展开。(译者注: 字面量一般指 [1, 2, 3] 或者 {name: "mdn"} 这种简洁的构造方式)
>
## RegExp 对象

下面的内容摘自《JavaScript高级程序设计第四版》：

ECMAScript 通过 RegExp 类型支持正则表达式。

正则表达式使用类似 Perl 的简洁语法来创建:

`let expression = /pattern/flags;`

这个正则表达式的 pattern(模式)可以是任何简单或复杂的正则表达式，包括字符类、限定符、 分组、向前查找和反向引用。每个正则表达式可以带零个或多个 flags(标记)，用于控制正则表达式 的行为。

下面给出了表示匹配模式的标记。

* g:全局模式，表示查找字符串的全部内容，而不是找到第一个匹配的内容就结束。 
* i:不区分大小写，表示在查找匹配时忽略 pattern 和字符串的大小写。
* m:多行模式，表示查找到一行文本末尾时会继续查找。
* y:粘附模式，表示只查找从 lastIndex 开始及之后的字符串。
* u:Unicode 模式，启用 Unicode 匹配。
* s:dotAll 模式，表示元字符.匹配任何字符(包括\n 或\r)。

RegExp 实例的主要方法是 exec()，主要用于配合捕获组使用。这个方法只接收一个参数，即要应用模式的字符串。

如果找到了匹配项，则返回包含第一个匹配信息的数组;如果没找到匹配项，则返回 null。

### JavaScript match() 方法

参考：https://www.runoob.com/jsref/jsref-match.html

match() 方法可在字符串内检索指定的值，或找到一个或多个正则表达式的匹配。

## element.innerHTML

`Element.innerHTML` 属性设置或获取 HTML 语法表示的元素的后代。

比如本次实践中，就运用这个技巧将`suggestions`类中的html换成了html变量表示的字符串，从而实现了以下效果：
```js
const stateName =  palce.state.replace(regex, `<span class="hl">${this.value}</span>`);
    return `
      <li>
        <span class="name">${cityName}, ${stateName}</span>
        <span class="population">${numberWithCommas(palce.population)}</span>
      </li>
    `;
```

## this.value
再次复习一下this的各种上下文情况。

```js
const matchArray = findMatches(this.value, cities);
```

比如这里，query查询到的类是一个input元素，那么调用的时候this就是这个元素。这个元素下面有value属性，代表输入的值。`this.value`就代表这个值。