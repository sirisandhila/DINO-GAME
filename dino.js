const dino = document.getElementById("dino");
const cactus = document.getElementById("cactus");

document.addEventListener("keydown", function(event) {
  if (event.code === "Space") {
    jump();
  }
});

function jump() {
  if (dino.classList != "jump") {
    dino.classList.add("jump");
    setTimeout(function() {
      dino.classList.remove("jump");
    }, 300);
  }
}

let isAlive = setInterval(function() {
  let dinoTop = parseInt(window.getComputedStyle(dino).getPropertyValue("top"));
  let cactusLeft = parseInt(window.getComputedStyle(cactus).getPropertyValue("left"));

  if (cactusLeft < 90 && cactusLeft > 50 && dinoTop >= 140) {
    alert("Game Over!");
  }
}, 10);

setInterval(function() {
  let cactusLeft = parseInt(window.getComputedStyle(cactus).getPropertyValue("left"));
  cactus.style.left = cactusLeft <= -20 ? "800px" : `${cactusLeft - 10}px`;
}, 50);

const jumpStyle = document.createElement("style");
jumpStyle.innerHTML = `
  #dino.jump {
    animation: jump 0.3s linear;
  }

  @keyframes jump {
    0% { bottom: 0; }
    50% { bottom: 100px; }
    100% { bottom: 0; }
  }
`;
document.head.appendChild(jumpStyle);
