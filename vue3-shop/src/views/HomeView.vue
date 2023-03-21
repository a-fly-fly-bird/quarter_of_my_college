<template>
    <h1>Hello World!</h1>
    <p v-text="data.name"></p>
    <!-- v-text的简写 -->
    <p>{{data.age}}</p>
    <!-- v-html传递 -->
    <p v-html="data.info"> </p>
    <!-- v-bind绑定 -->
    <p :data="dataVal"></p>
    <!-- class 类名绑定， class可以叠加-->
    <p :class="{'red': data.isRed}">我是红色的</p>
    <!-- v-if 和 v-show -->
    <p v-if="data.isIf">v-if是否渲染这个元素</p>
    <p v-show="data.isShow">是否show这个元素</p>
    <!-- v-for -->
    <ul>
        <li v-for="(item, index) in data.userList" :key="item">
            学生{{index}}姓名:{{item.userName}},
            学生{{index}}年龄:{{item.userAge}}
        </li>
    </ul>
</template>

<script setup>
import {ref} from 'vue';

const data = ref({
    name: 'ty',
    age: 20,
    info: "<i>我是斜体字</i>",
    dataVal: 20,
    isRed: true,
    isIf: true,
    isShow: false,
    userList: [
        {
            userName: 'user1',
            userAge: 10
        },
        {
            userName: 'user2',
            userAge: 20
        },
        {
            userName: 'user3',
            userAge: 30
        }
    ]
})
</script>

<style>
    .red{
        color: red;
    }
</style>
