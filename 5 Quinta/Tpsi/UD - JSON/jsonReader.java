/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package jsonobject.terminal;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

/**
 *
 * @author Francesco
 */
public class jsonReader {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /* CREAZIONE CONNESIONE AL SERVER HTTP PER STRINGA JSON */
                URL url = null;
                try {
                    url = new URL("http://scuola.localhost/Quinta/Tpsi/UD%20-%20JSON/getjson.php");
                } catch (MalformedURLException ex) {
                    Logger.getLogger(JSonObjectTerminal.class.getName()).log(Level.SEVERE, null, ex);
                }

                HttpURLConnection con = null;
                try {
                    con = (HttpURLConnection) url.openConnection();
                } catch (IOException ex) {
                    Logger.getLogger(JSonObjectTerminal.class.getName()).log(Level.SEVERE, null, ex);
                }
                try {
                    con.setRequestMethod("GET");
                } catch (ProtocolException ex) {
                    Logger.getLogger(JSonObjectTerminal.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                // Preparo il parser, scompone le diverse coppie chiave:valore e costruisce il jsonObject.
                JSONParser jsonParser = new JSONParser();
                JSONObject jsonObject = null;
                try {
                    jsonObject = (JSONObject)jsonParser.parse(
                            new InputStreamReader(con.getInputStream(), "UTF-8"));
                } catch (ParseException ex) {
                    Logger.getLogger(JSonObjectTerminal.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
            Logger.getLogger(JSonObjectTerminal.class.getName()).log(Level.SEVERE, null, ex);
        }
                
        // Visualizzo i dati contenuti nel JSON Object, richiamandoli grazie alle diverse chiavi.
        System.out.println(jsonObject.get("id"));
        System.out.println(jsonObject.get("nome"));
        System.out.println(jsonObject.get("posizione"));
        System.out.println(jsonObject.get("anno_attivazione"));
        //System.out.println(jsonObject.get("nazionalita"));
    }
}