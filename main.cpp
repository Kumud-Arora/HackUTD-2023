let carPayment = +document.getElementById("mcp").value;
let ccPayment = +document.getElementById("mccp").value;
let monthlyDebt;
let grossIncome = +document.getElementById("gmi").value;
let mortgagePayment = +document.getElementById("mmp").value;
let decision1; 
let boolvalue; 
let potential; 
let boolStatement; 
let creditScore = +document.getElementById("cs").value;
let dti_percent;
let loan = +document.getElementById("loan").value;
let downPayment = +document.getElementById("dpa").value;
let HomeValue = +document.getElementById("hav").value;
let ltv;
let fedti;
let studentLoan = +document.getElementById("slp").value;
let outputElement = document.getElementById("output");

// Load the Visualization API and the corechart package.
    google.charts.load('current', { 'packages': ['corechart'] });

    // Set a callback to run when the Google Visualization API is loaded.
    google.charts.setOnLoadCallback(drawChart);

    // Callback that creates and populates a data table,
    // instantiates the pie chart, passes in the data and
    // draws it.
    function drawChart() {

      // Create the data table.
      var data = new google.visualization.DataTable();
      data.addColumn('string', 'Factors');
      data.addColumn('number', 'Value');
      data.addRows([
        ['Car Payment', carPayment],
        ['Credit Card Payment', ccPayment],
        ['Gross Income', grossIncome],
        ['Mortage Payment', mortgagePayment],
        ['Credit Score', creditScore],
        ['Loan', loan],
        ['Down Payment', downPayment],
        ['Home Value', HomeValue],
        ['Student Loan', studentLoan]
      ]);

      // Set chart options
      var options = {
        'title': 'Visualization of your Debt and your Income',
        'width': 400,
        'height': 300
      };

      // Instantiate and draw our chart, passing in some options.
      var chart = new google.visualization.PieChart(document.getElementById('chart_div'));
      chart.draw(data, options);
    }


function DTI() {

  // calculating debt
  monthlyDebt = carPayment + ccPayment + mortgagePayment + studentLoan;
  dti_percent = (monthlyDebt / grossIncome) * 100;
  
  // displaying DTI
  outputElement.innerHTML += "<p>Your debt income ratio is " + dti_percent + " percent.</p>";

  if (dti_percent <= 43 && dti_percent >= 0) {
    decision1 = true;
    if (dti_percent > 36 && dti_percent <= 43) {
    outputElement.innerHTML +=(
        `While there are lenders who accept a ${dti_percent} ratio, there is a risk associated as lenders prefer DTI scores lower than 36.`
    );
}

    if (dti_percent > 43) {
      let advice;
      decision1 = false;
      advice =
        "It is advisable to lower your DTI score. One way to do so would be to shift your high interest loans to a low interest credit card. Be aware that having many credit cards can also impact your ability to purchase a home negatively.";
      outputElement.innerHTML +=(advice);
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


// if (DTI() === false) {
//   potential = false;
//   outputElement.innerHTML += "<p> Your FEDTI is " + fedti + " .</p>";
//   outputElement.innerHTML += "<p> You are not eligible to purchase a house </p>";
// }

// else if (FEDTI() === false) {
//   potential = false;
//   outputElement.innerHTML += "<p> Your FEDTI is " + fedti + " .</p>";
//   outputElement.innerHTML += "<p> You are not eligible to purchase a house </p>";
// }
  
// else if (boolvalue === false) {
//   potential = false;
//   outputElement.innerHTML += "<p> Your FEDTI is " + fedti + " .</p>";
//   outputElement.innerHTML += "<p> You are not eligible to purchase a house </p>";
// }
  
// else {
//   outputElement.innerHTML += "<p> You're FEDTI is " + fedti + ". </p>";
//   outputElement.innerHTML += "<p> You are eligible to purchase a house!!!</p>";
// }

//function unPotential in js

function unPotential(){

    outputElement.innerHTML +=  (" <p>You are not eligible to purchase a house. </p>");
    
  if (DTI() === false) {
      
        outputElement.innerHTML +=  " <p> Your DTI score is high. You must bring it down to at least 43. </p>"; 
        outputElement.innerHTML +=  " <p> A DTI score of under 28 is ideal, while a score under 36 is good. </p>";
        outputElement.innerHTML +=  "<p>Here are a couple steps you can take to improve your score: </p>" ; 
        outputElement.innerHTML +=  "<p>1: Secure a higher income. </p>"  ; 
        outputElement.innerHTML +=  "<p>2. Pay off loans early. </p>" ; 
        outputElement.innerHTML +=  "<p>3. Secure longer loan terms. </p>" ; 
        outputElement.innerHTML +=  "<p>4. Shift high interest loans to low interest loans. </p>"; 
        outputElement.innerHTML +=  "<p>5. Reduce monthly spendings. <p>" ; 
        outputElement.innerHTML +=  "<p>6. Avoid taking out new loans and making huge spendings. <p>"; 
        outputElement.innerHTML +=  "<p>7. Pay off loans early. <p>"; 
        
    }
    
    if (FEDTI() === false){
      outputElement.innerHTML += "<p>Your FEDTI score is high. You must bring it to atleast 28. </p>";
        outputElement.innerHTML +=  "<p>Here are a couple steps you can take to improve your score:</p> "; 
      outputElement.innerHTML += "<p>1.Decrease your mortgage payment by negotaitng longer loan periods. </p>";
        outputElement.innerHTML +=  "<p>2. Secure higher income. Look for additional jobs. </p>"; 
        
    }
    
    if (creditScore < 640){
        outputElement.innerHTML +=  "<p>Your credit score is low. A good credit score is above 640.</p> "; 
        outputElement.innerHTML +=  "<p>Here are some steps you can take to improve your credit score.</p> "; 
        outputElement.innerHTML +=  "<p>1. Complete payments within deadlines. </p>"; 
        outputElement.innerHTML +=  "<p>2. Dispute any errors founds in credit report. </p> "; 
        outputElement.innerHTML +=  "<p>3. Limit the number of credit cards you open.</p> "; 
        outputElement.innerHTML +=  "<p>4. Keep all credit card accounts open. </p>"; 
        outputElement.innerHTML +=  "<p>5. Pay off debts as soon as possible. </p>"; 
        
    }
    
    if (ltv === false){
        outputElement.innerHTML +=  "<p>Your LTV score is low. An average LTV score should be at least 80. </p>"; 
        outputElement.innerHTML +=  "<p>Here are a couple steps you can take to improve your LTV score. </p>"; 
        outputElement.innerHTML +=  "<p>1. Increase your down payment. </p>"; 
        outputElement.innerHTML +=  "<p>2. Purchase a less expensive home/property. </p>"; 
        outputElement.innerHTML +=  "<p>3. Secure a short loan term. </p>" ; 
    }
}

//if else logic in js
if (potential === false)
    {
        outputElement.innerHTML +=(`You're FEDTI is ${fedti}.`);
        unPotential();
        
    }
    else
    {
        outputElement.innerHTML +=(`You're FEDTI is ${fedti}.`);
        outputElement.innerHTML +=  ("You are eligible!!");
    }
