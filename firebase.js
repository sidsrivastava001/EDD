// Import the functions you need from the SDKs you need
//import { initializeApp } from "firebase/app";
//import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyCXxpDEQ_RcDfbcjpO95FZhTGDDWlHKgEw",
    authDomain: "dip-coater.firebaseapp.com",
    databaseURL: "https://dip-coater-default-rtdb.firebaseio.com",
    projectId: "dip-coater",
    storageBucket: "dip-coater.appspot.com",
    messagingSenderId: "562703692753",
    appId: "1:562703692753:web:4d36180b7ec03ba3a666f0",
    measurementId: "G-8ZJYBQB7NY"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);


//function whose purpose is to gather data from website (prepare data)
var speed, iTime, dTime, distance
//funcitons to gather data
function dataPrep() {
    speed = document.getElementById('speed').value;
    iTime = document.getElementById('iTime').value;
    dTime = document.getElementById('dTime').value;
    distance = document.getElementById('distance').value;
    console.log("hi")
}

// Update Data, updates data to the database
document.getElementById('submit').onclick = function(){
    dataPrep();
    // if you use 'set' it will replace existing fields with new ones
    // use 'update' to only modify existing fields

    firebase.database().ref('Record').set({
        Speed: speed,
        ImmersionTime: iTime,
        DryingTIme: dTime,
        Distance: distance,
    });
    //toast("Update Complete!");
}
