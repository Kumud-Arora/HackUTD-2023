let carPayment = document.getElementById("mcp").value;
let ccPayment = document.getElementById("mccp").value;
let monthlyDebt = 0;
let grossIncome = document.getElementById("gmi").value
let mortgagePayment = document.getElementById("mmp").value
let decision1; 
let boolvalue; 
let potential; 
let boolStatement; 
let creditScore = document.getElementById("cs").value
let dti_percent;
let loan = document.getElementById("loan").value;
let downPayment = document.getElementById("dpa").value;
let HomeValue = document.getElementById("hav").value;
let ltv;
let fedti;
let studentLoan = document.getElementById("slp").value;

function DTI() {

  // calculating debt
  monthlyDebt = carPayment + ccPayment + mortgagePayment + studentLoan;
  dti_percent = (monthlyDebt / grossIncome) * 100;

  // displaying DTI
  console.log(`Your debt income ratio is ${dti_percent} percent.`);

  if (dti_percent <= 43 && dti_percent >= 0) {
    decision1 = true;
    if (dti_percent > 36 && dti_percent <= 43) {
    console.log(
        `While there are lenders who accept a ${dti_percent} ratio, there is a risk associated as lenders prefer DTI scores lower than 36.`
    );
}


    if (dti_percent > 43) {
      let advice;
      decision1 = false;
      advice =
        "It is advisable to lower your DTI score. One way to do so would be to shift your high interest loans to a low interest credit card. Be aware that having many credit cards can also impact your ability to purchase a home negatively.";
      console.log(advice);
    }
  }

  return decision1;
}

function FEDTI() {
  let decision2;

  fedti = (mortgagePayment / grossIncome) * 100;

  if (fedti <= 28) {
    decision2 = true;
  } else {
    decision2 = false;
  }

  console.log(`You're FEDTI is ${fedti}.`);

  return decision2;
}


ltv = (loan / HomeValue) * 100;

if (creditScore >= 640) {
  boolStatement = true;
} else if (creditScore < 640) {
  boolStatement = false;
}

if (ltv >= 80.0) {
  boolvalue = true;
} else if (ltv < 80.0) {
  boolvalue = false;
}

if (
  DTI() === false ||
  FEDTI() === false ||
  boolvalue === false ||
  creditScore < 640
) {
  potential = false;
  console.log("You are not eligible to purchase a house.");
} else {
  console.log("You are eligible!!");
}
