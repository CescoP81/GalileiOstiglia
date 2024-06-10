// definizione funzioni
function popolaMarca(){
   let z = document.querySelector("#Marca");     // recupero il riferimento alla 
   if(z){   // controllo che il riferimento esista.
      z.addEventListener("change",popolaMezzo);           
      var newOption;
      fetch('jsonMarca.php')
         .then(response => response.json())
         .then(mioRisultato => {
            for(let i=0; i<mioRisultato.length; i++){
               //const myJSON = JSON.stringify(mioRisultato[i]);
               //const record = JSON.parse(myJSON);
               newOption = document.createElement("option");
               newOption.text = mioRisultato[i].descrizione;
               newOption.value = mioRisultato[i].id;
               z.add(newOption);                  
            }
         }
      );
      popolaMezzo();
   }
}
         
function popolaMezzo(){
   let z = document.querySelector("#Marca");
   let idMarca = z.value;
   //alert(idZona);
   let im = document.querySelector("#Mezzo");
   
   // fase di svuotamento select dalle precedenti option.
   let numberOfChild = im.childElementCount;
   //alert(numberOfChild);
   if(numberOfChild > 0){
      for(let i=0; i<numberOfChild; i++)
         im.remove("option");
   }

   // fase di creazione delle nuove option basate sul json recuperato dalla fetch.
   var newOption;
   let httpRequest = 'jsonMezzo.php?idMarca='+idMarca;
   //alert(httpRequest);
   fetch(httpRequest)
   .then(response => response.json())
   .then(mioRisultato => {
      for(let i=0; i<mioRisultato.length; i++){
         newOption = document.createElement("option");
         newOption.text = mioRisultato[i].descrizione;
         newOption.value = mioRisultato[i].id;
         im.add(newOption);                  
      }
   }
   ); //*/           
}

// richiamo funzioni iniziali
popolaMarca();