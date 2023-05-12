// JSON 파일 불러오기
fetch(
  "https://raw.githubusercontent.com/909ma/909ma.github.io/main/Brain Helper/data/Subject.json"
)
  .then(function (response) {
    return response.json();
  })
  .then(function (data) {
    subjectList = data;
    showSubjectOptions();
    showQuestion(currentQuestionIndex);
  });

// HTML 요소 선택
var subjectSelect = document.getElementById("subjectSelect");
var questionDiv = document.getElementById("question");
var revealButton = document.getElementById("revealButton");
var prevButton = document.getElementById("prevButton");
var nextButton = document.getElementById("nextButton");
var gotoInput = document.getElementById("gotoInput");
var gotoButton = document.getElementById("gotoButton");

// 초기 상태 설정
var currentQuestionIndex = 0;

// 과목 목록 표시 함수
function showSubjectOptions() {
  subjectList.forEach(function (subject) {
    var option = document.createElement("option");
    option.value = subject.value;
    option.text = subject.name;
    subjectSelect.appendChild(option);
  });
}

// 질문과 답 표시 함수
function showQuestion(index) {
  var selectedSubjectValue = subjectSelect.value;
  var questionDataUrl =
    "https://raw.githubusercontent.com/909ma/909ma.github.io/main/Brain Helper/data/" +
    selectedSubjectValue +
    ".json";

  // JSON 파일 불러오기
  fetch(questionDataUrl)
    .then(function (response) {
      return response.json();
    })
    .then(function (data) {
      questionList = data;
      var questionData = questionList[index];
      questionDiv.innerHTML =
        "<p>" +
        questionData.question +
        "</p>" +
        '<p class="answer hidden">' +
        questionData.answer +
        "</p>";

      // 이전 버튼 활성화 여부 설정
      prevButton.disabled = index === 0;

      // 다음 버튼 활성화 여부 설정
      nextButton.disabled = index === questionList.length - 1;
    });
}

// 과목 선택 변경 시 이벤트 처리
subjectSelect.addEventListener("change", function () {
  currentQuestionIndex = 0;
  showQuestion(currentQuestionIndex);
});

// 정답 보기 버튼 클릭 시 이벤트 처리
revealButton.addEventListener("click", function () {
  var answerElement = questionDiv.querySelector(".answer");
  answerElement.classList.remove("hidden");
});

// 이전 버튼 클릭 시 이벤트 처리
prevButton.addEventListener("click", function () {
  if (currentQuestionIndex > 0) {
    currentQuestionIndex--;
  } else if (currentQuestionIndex === 0) {
    currentQuestionIndex = questionList.length - 1;
  }
  showQuestion(currentQuestionIndex);
});

// 다음 버튼 클릭 시 이벤트 처리
nextButton.addEventListener("click", function () {
  if (currentQuestionIndex < questionList.length - 1) {
    currentQuestionIndex++;
  } else if (currentQuestionIndex === questionList.length - 1) {
    currentQuestionIndex = 0;
  }
  showQuestion(currentQuestionIndex);
});

// 이동 버튼 클릭 시 이벤트 처리
gotoButton.addEventListener("click", function () {
  var gotoIndex = parseInt(gotoInput.value) - 1;
  if (gotoIndex >= 0 && gotoIndex < questionList.length) {
    currentQuestionIndex = gotoIndex;
    showQuestion(currentQuestionIndex);
    gotoInput.value = "";
  } else {
    alert("유효한 질문 번호를 입력해주세요.");
  }
});

// 키보드 이벤트 처리
document.addEventListener("keydown", function (event) {
  if (event.key === "ArrowLeft") {
    // 왼쪽 화살표 키
    if (currentQuestionIndex > 0) {
      currentQuestionIndex--;
      showQuestion(currentQuestionIndex);
    }
  } else if (event.key === "ArrowRight") {
    // 오른쪽 화살표 키
    if (currentQuestionIndex < questionList.length - 1) {
      currentQuestionIndex++;
      showQuestion(currentQuestionIndex);
    }
  } else if (event.key === "ArrowUp") {
    // 위쪽 화살표 키
    var answerElement = questionDiv.querySelector(".answer");
    answerElement.classList.remove("hidden");
  }
});
