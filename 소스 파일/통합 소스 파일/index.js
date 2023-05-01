let currentQuestionIndex = 1;
const questionContainer = document.querySelector(".question-container");
const questions = document.querySelectorAll(".question");
const answerBtn = document.querySelector(".show");
const answers = document.querySelectorAll(".answer");

//Next 기능
function nextQuestion() {
  questions[currentQuestionIndex - 1].classList.remove("active");
  currentQuestionIndex =
    currentQuestionIndex === questions.length ? 1 : currentQuestionIndex + 1;
  questions[currentQuestionIndex - 1].classList.add("active");
}

//Back 기능
function backQuestion() {
  questions[currentQuestionIndex - 1].classList.remove("active");
  currentQuestionIndex =
    currentQuestionIndex === 1 ? questions.length : currentQuestionIndex - 1;
  questions[currentQuestionIndex - 1].classList.add("active");
}

//Go to 기능
function goToQuestion() {
  // 이전에 선택된 문제를 지웁니다.
  //questions.forEach((question) => question.classList.remove("active"));
  questions[currentQuestionIndex - 1].classList.remove("active");

  // 입력된 문제 번호를 가져옵니다.
  const questionNum = document.getElementById("questionNumInput").value;
  currentQuestionIndex = questionNum - 1;
  // 해당 문제 번호에 해당하는 문제 ID를 가져옵니다.
  const questionId = `question${questionNum}`;

  // 해당 문제가 존재하는지 확인합니다.
  const targetQuestion = document.getElementById(questionId);
  if (!targetQuestion) {
    alert(`Question ${questionNum} does not exist!`);
    return;
  }
  // 해당 문제 위치로 점프합니다.
  questions[questionNum - 1].classList.add("active");
}

// 엔터키를 눌렀을 때 go to 버튼 클릭
document.addEventListener("keydown", function (event) {
  if (event.keyCode === 13) {
    event.preventDefault(); // 기본 이벤트를 취소하여 페이지 이동 방지
    document.getElementById("goToQuestion").click(); // go to 버튼 클릭
  }
});

//해답 보이기, 가리기 기능
let count = 0;
answerBtn.onclick = function () {
  for (const iterator of answers) {
    if (iterator.style.display === "none") {
      iterator.style.display = "block";
      //answer.forEach((answer) => (answer.style.display = "block"));
      //answerBtn.textContent = "Hide";
    } else {
      iterator.style.display = "none";
      //answer.forEach((answer) => (answer.style.display = "none"));
      //answerBtn.textContent = "Show";
    }
  }

  if (count % 2 == 0) {
    answerBtn.textContent = "Hide";
  } else {
    answerBtn.textContent = "Show";
  }
  count++;
};

//빠른 시전 기능
document.addEventListener("keydown", function (event) {
  if (event.keyCode === 37) {
    // 왼쪽 화살표
    backQuestion();
  } else if (event.keyCode === 39) {
    // 오른쪽 화살표
    nextQuestion();
  } else if (event.keyCode === 38) {
    // 위쪽 화살표
    for (const iterator of answers) {
      if (iterator.style.display === "none") {
        iterator.style.display = "block";
      } else {
        iterator.style.display = "none";
      }
    }
  }
});