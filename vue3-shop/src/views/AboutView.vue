<template>
  <div>
    <h2>Vue3的声明周期</h2>
    <!-- 声明周期 -->
    <div id="dom">{{data.msg}}</div>
    <!-- 事件 -->
    <button @click="greet">click me</button>
    <hr>
    <!-- 双向绑定 -->
    <input type="text" placeholder="请输入" v-model="data.userName">
    <textarea placeholder="请输入" cols="30" rows="10" v-model="data.userInput"></textarea>
    <p>{{data.userName}}</p>
    <p>{{data.userInput}}</p>
    <button @click="submit">提交</button>
  </div>
</template>

<script setup>
import {onMounted, onBeforeMount,ref} from 'vue';

const data = ref({
  msg: "你好",
  userName: "",
  userInput: "",
})

// 数据渲染前
onBeforeMount(()=>{
  console.log("onBeforeMount", document.querySelector("#dom"))
})

// 数据渲染后
onMounted(()=>{
  console.log("onBeforeMount", document.querySelector("#dom"))
})

function greet(event) {
  alert("你好")
  // `event` 是 DOM 原生事件
  if (event) {
    alert(event.target.tagName)
  }
}

function submit() {
  // ES6的语法，我也看过，字符串免去写加号
  alert(`${data.value.userName}说的话是${data.value.userInput}`)
}
</script>
