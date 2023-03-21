const player = document.querySelector('.player');
const video = player.querySelector('.viewer');
const progress = player.querySelector('.progress');
const progressBar = player.querySelector('.progress__filled');
const toggle = player.querySelector('.toggle');
const skipButtons = player.querySelectorAll('[data-skip]');
const ranges = player.querySelectorAll('.player__slider');

// toggle 意思：转换
function togglePlay() {
  const method = video.paused ? 'play' : 'pause';
  // [] 获取方法名，然后加括号进行调用
  video[method]();
}

function updateButton(){
    const icon = this.paused ? '►' : '❚ ❚';
    toggle.textContent = icon;
}

function toggleKeyPlay(e){
    console.log(e);
    if(e.keyCode == 32){
        togglePlay();
    }
}
function skip(){
    video.currentTime += parseFloat(this.dataset.skip);
    console.log(video.currentTime);
}

function range(){
    video[this.name] = this.value;
}

function scrub(e){
    const scrubTime = (e.offsetX / progress.offsetWidth) * video.duration;
    video.currentTime = scrubTime;
}

function handleProgress(){
    const percent = (video.currentTime / video.duration) * 100;
    progressBar.style.flexBasis = `${percent}%`;
}

video.addEventListener('click', togglePlay);
video.addEventListener('play', updateButton);
video.addEventListener('pause', updateButton);
toggle.addEventListener('click', togglePlay);
window.addEventListener('keydown', toggleKeyPlay);
// 分两步, 这步很神奇
video.addEventListener('timeupdate', handleProgress);

skipButtons.forEach(skipButtom => skipButtom.addEventListener('click', skip));
ranges.forEach(range => range.addEventListener('change', range));
ranges.forEach(range => range.addEventListener('mousemove', range));

progress.addEventListener('click', scrub);

let mousedown = false;

// 学到了, mousedown 为 true 时，才会执行 scrub(e)
progress.addEventListener('mousemove', (e) => {
    if(mousedown){
        scrub(e);
    }else{
        console.log(e);
    }
});
progress.addEventListener('mousedown', () => mousedown = true);
progress.addEventListener('mouseup', () => mousedown = false);

// TODO 滑动预览
