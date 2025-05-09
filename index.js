// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyC3IbphCBqVryTglPBE5xfQATUnFQ7gopQ",
  authDomain: "httpsproject-faa04.firebaseapp.com",
  projectId: "httpsproject-faa04",
  storageBucket: "httpsproject-faa04.firebasestorage.app",
  messagingSenderId: "884876686687",
  appId: "1:884876686687:web:ee9ae53f95a2294d2172ea",
  measurementId: "G-58306CJ41S"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);