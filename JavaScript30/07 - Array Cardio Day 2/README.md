# 知识点

## some 和 every

> 两者的相同之处是，都接受一个函数作为参数，对数组元素都执行一次此函数，都不会改变原数组的值。不同之处在于返回条件不同：
>
> some() 中直到某个数组元素使此函数为 true，就立即返回 true。所以可以用来判断一个数组中，是否存在某个符合条件的值。
> 
> 而 every() 中除非所有值都使此函数为 true，才会返回 true 值，否则为 false。主要用处，即判断是否所有元素都符合条件。


## find 和 fineIndex

> 这两个 ES6 的新特性类似于 some() ，但对于符合条件的元素，返回值不是布尔类型。不一样的地方在于，find() 返回的是这个元素的值（或 undefined），而 findIndex() 返回的是这个元素的索引（或 -1）。
>
参考： https://blog.csdn.net/qq_39652441/article/details/79248127

可以看到，find只查出第一个符合条件的结果像例子里是直接返回了一个对象而不是数组。

## slice 和 splice
### Array.prototype.splice()

参考： https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array/splice

splice() 方法通过删除或替换现有元素或者原地添加新的元素来修改数组，并以数组形式返回被修改的内容。此方法会改变原数组。

### Array.prototype.slice()
slice() 方法返回一个新的数组对象，这一对象是一个由 begin 和 end 决定的原数组的浅拷贝（包括 begin，不包括end）。原始数组不会被改变。