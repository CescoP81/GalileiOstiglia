let btn = document.querySelector("#btnVerifica");
            btn.addEventListener("click",verificaNumeri);

            function verificaNumeri(){
                let v1 = parseInt(document.querySelector("#v1").value);
                let v2 = parseInt(document.querySelector("#v2").value);
                let v3 = parseInt(document.querySelector("#v3").value);
                let r1 = document.querySelector("#r1");
                let r2 = document.querySelector("#r2");
                let r3 = document.querySelector("#r3");

                if(v1<v2 && v2<v3){
                    r1.innerHTML = v1;
                    r2.innerHTML = v2;
                    r3.innerHTML = v3;
                    r1.style.background = "rgb(0,200,0)";
                    r2.style.background = "rgb(0,200,0)";
                    r3.style.background = "rgb(0,200,0)";
                }
                else{
                    let min = v1;
                    if(v2 < min) min = v2;
                    if(v3 < min) min = v3;
                    let max = v1;
                    if(v2 > max) max = v2;
                    if(v3 > max) max = v3;

                    r1.innerHTML = min;
                    r1.style.background = "rgb(200,0,0)";
                    r3.innerHTML = max;
                    r3.style.background = "rgb(0,200,0)";

                    r2.style.background = "rgb(255,255,255";
                    r2.innerHTML = "<>";
                }
            }