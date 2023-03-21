本节课主要讲的是map,reduce函数式编程。

箭头函数与本章的函数结合，可以编写出非常简洁高效的代码。

# 知识点
## sort()排序顺序
参数compareFn 可选用来指定按某种顺序进行排列的函数。如果省略，元素按照转换为的字符串的各个字符的 Unicode 位点进行排序。
* 如果 compareFn(a, b) 大于 0，b 会被排列到 a 之前。
* 如果 compareFn(a, b) 小于 0，那么 a 会被排列到 b 之前；
* 如果 compareFn(a, b) 等于 0，a 和 b 的相对位置不变。

## reduce()
reduce()的用法可以参考最后一个例子进行很好的理解。这里单独再拿出来。
```js
const data = ['car', 'car', 'truck', 'truck', 'bike', 'walk', 'car', 'van', 'bike', 'walk', 'car', 'van', 'car', 'truck'];
const transportation = data.reduce((obj, item) => {
    if(!obj[item]){
    obj[item] = 0;
    }
    obj[item]++;
    return obj;
}, {});
console.log(transportation);
```
