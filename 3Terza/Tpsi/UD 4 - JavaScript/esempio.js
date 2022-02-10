// gestione button II
function mioClick(){
   alert("Eccomi qua...II");
}

// gestione botton III
var x = document.getElementById("btn1");
x.addEventListener("click", mioClickII);

function mioClickII(){
   document.getElementById("finestra").innerHTML = "Eccomi da bottone 3<br />";
   //alert("Eccomi qui per la terza volta...");
   let i;
   for(i=1; i<=10; i++){
      console.log(i);
      document.getElementById("finestra").innerHTML += i+" ";
   }

}

var y = document.getElementById("bottone");
y.addEventListener("mouseover",evidenzia);

function evidenzia(y){
   document.getElementById("finestra").innerHTML += "Passaggio<br />";
}