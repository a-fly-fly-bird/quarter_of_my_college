function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function demo() {
    setTimeout(()=>{console.log("1")}, 1000);
    console.log('2');
    await sleep(3000);
    console.log('3');
}

// JavaScript引擎是单线程，它会强制异步事件排队等待执行
demo()
console.log('4');