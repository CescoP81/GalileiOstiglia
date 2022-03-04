// definizione funzioni
function popolaZona(){

   let z = document.querySelector("#Zona");     // recupero il riferimento alla 
   if(z){
      z.addEventListener("change",popolaImmobile);           
      var newOption;
      fetch('require/jsonZona.php')
         .then(response => response.json())
         .then(mioRisultato => {
            for(let i=0; i<mioRisultato.length; i++){
               //const myJSON = JSON.stringify(mioRisultato[i]);
               //const record = JSON.parse(myJSON);

               newOption = document.createElement("option");
               newOption.text = mioRisultato[i].nome;
               newOption.value = mioRisultato[i].id;
               z.add(newOption);                  
            }
         }
      );
      popolaImmobile();
   }
}
         
function popolaImmobile(){
   let z = document.querySelector("#Zona");
   let idZona = z.value;
   let im = document.querySelector("#Immobile");
   let numberOfChild = im.childElementCount;
   //alert(numberOfChild);
   if(numberOfChild > 0){
      for(let i=0; i<numberOfChild; i++)
         im.remove("option");
   }

   var newOption;
   let httpRequest = 'require/jsonImmobile.php?idZona='+idZona;
   //alert(httpRequest);
   fetch(httpRequest)
   .then(response => response.json())
   .then(mioRisultato => {
      for(let i=0; i<mioRisultato.length; i++){
         newOption = document.createElement("option");
         newOption.text = mioRisultato[i].nome;
         newOption.value = mioRisultato[i].id;
         im.add(newOption);                  
      }
   }
   );            
}

// richiamo funzioni iniziali
popolaZona();