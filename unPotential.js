//function unPotential in js
void unPotential(){
    console.log  ("You are not eligible to purchase a house. ")  ;
    
    if (DTI() === false){
        console.log  ("\nYour DTI score is high. You must bring it down to at least 43."); 
        console.log  ("A DTI score of under 28 is ideal, while a score under 36 is good." ) ;
        console.log  ("Here are a couple steps you can take to improve your score: ")  ; 
        console.log  ("1: Secure a higher income. ")  ; 
        console.log  ("2. Pay off loans early. ")  ; 
        console.log  ("3. Secure longer loan terms. ")  ; 
        console.log  ("4. Shift high interest loans to low interest loans. "); 
        console.log  ("5. Reduce monthly spendings. ")  ; 
        console.log  ("6. Avoid taking out new loans and making huge spendings. "); 
        console.log  ("7. Pay off loans early. "); 
        
    }
    
    if (FEDTI() === false){
        console.log  ("\nYour FEDTI score is high. You must bring it to atleast 28. "); 
        console.log  ("Here are a couple steps you can take to improve your score: "); 
        console.log  ("1. Decrease your mortgage payment by negotaitng longer loan periods. "); 
        console.log  ("2. Secure higher income. Look for additional jobs. "); 
        
    }
    
    if (creditScore < 640){
        console.log  ("\nYour credit score is low. A good credit score is above 640. "); 
        console.log  ("Here are some steps you can take to improve your credit score. "); 
        console.log  ("1. Complete payments within deadlines. "); 
        console.log  ("2. Dispute any errors founds in credit report.  "); 
        console.log  ("3. Limit the number of credit cards you open. "); 
        console.log  ("4. Keep all credit card accounts open. "); 
        console.log  ("5. Pay off debts as soon as possible. "); 
        
    }
    
    if (ltv === false){
        console.log  ("\nYour LTV score is low. An average LTV score should be at least 80. "); 
        console.log  ("Here are a couple steps you can take to improve your LTV score. "); 
        console.log  ("1. Increase your down payment. ") ; 
        console.log  ("2. Purchase a less expensive home/property. "); 
        console.log  ("3. Secure a short loan term. ") ; 
    }
}

//if else logic in js
if (potential === false)
    {
        console.log(`You're FEDTI is ${fedti}.`);
        unPotential();
        
    }
    else
    {
        console.log(`You're FEDTI is ${fedti}.`);
        console.log  "You are eligible!!";
    }
