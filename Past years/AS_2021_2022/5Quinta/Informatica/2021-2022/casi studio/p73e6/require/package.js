// definizione funzioni
function popolaZona(){

   let z = document.querySelector("#Zona");     // recupero il riferimento alla 
   if(z){   // controllo che il riferimento esista.
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
   //alert(idZona);
   let im = document.querySelector("#Immobile");
   
   // fase di svuotamento select dalle precedenti option.
   let numberOfChild = im.childElementCount;
   //alert(numberOfChild);
   if(numberOfChild > 0){
      for(let i=0; i<numberOfChild; i++)
         im.remove("option");
   }

   // fase di creazione delle nuove option basate sul json recuperato dalla fetch.
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