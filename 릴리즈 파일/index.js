const questionContainer = document.querySelector(".question-container");
const questions = document.querySelectorAll(".question");
const answerBtn = document.querySelector(".show");
const answers = document.querySelectorAll(".answer");
let currentQuestionIndex = questions.length;

//Next 기능
function nextQuestion() {
  questions.forEach((question) => question.classList.remove("active"));
  currentQuestionIndex =
    currentQuestionIndex === questions.length ? 1 : currentQuestionIndex + 1;
  questions[currentQuestionIndex - 1].classList.add("active");
}

//Back 기능
function backQuestion() {
  questions.forEach((question) => question.classList.remove("active"));
  currentQuestionIndex =
    currentQuestionIndex === 1 ? questions.length : currentQuestionIndex - 1;
  questions[currentQuestionIndex - 1].classList.add("active");
}

//Go to 기능
function goToQuestion() {
  // 이전에 선택된 문제를 지웁니다.
  questions.forEach((question) => question.classList.remove("active"));

  // 입력된 문제 번호를 가져옵니다.
  const questionNumInput = document.getElementById("questionNumInput");
  const questionNum = Number(questionNumInput.value);

  // 문제 번호가 숫자가 아니거나 범위를 벗어난 값이면 경고 메시지를 표시합니다.
  if (isNaN(questionNum) || questionNum < 1 || questionNum > questions.length) {
    alert(`Invalid question number: ${questionNumInput.value}`);
    questionNumInput.value = "";
    return;
  }

  // 해당 문제 번호에 해당하는 문제 ID를 가져옵니다.
  const questionId = `question${questionNum}`;

  // 해당 문제가 존재하는지 확인합니다.
  const targetQuestion = document.getElementById(questionId);
  if (!targetQuestion) {
    alert(`Question ${questionNum} does not exist!`);
    return;
  }

  // 해당 문제 위치로 점프합니다.
  currentQuestionIndex = questionNum;
  questions[currentQuestionIndex - 1].classList.add("active");
}

//해답 보이기, 가리기 기능
answerBtn.onclick = function () {
  for (const iterator of answers) {
    if (iterator.style.display === "none") {
      iterator.style.display = "block";
      answerBtn.textContent = "Hide";
    } else {
      iterator.style.display = "none";
      answerBtn.textContent = "Show";
    }
  }
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
        answerBtn.textContent = "Hide";
      } else {
        iterator.style.display = "none";
        answerBtn.textContent = "Show";
      }
    }
  }
});
