const worker=new Worker("worker.js");
worker.onmessage=(event)=>{
    const users=event.data;
    const userdiv=document.getElementById("users");
    userdiv.innerHTML="";
    if(!users||users.length===0){
        userdiv.textContent="No users returned";
        return;
    }
    users.forEach(user=>{
        const status=user.active? "Active":"Inactive";
        const p=document.createElement("p");
    });
};
worker.onerror=(error)=>{
    const usersDiv=document.getElementById("users");
    usersDiv.textContent=`Worker error: ${error.message}`;
}
worker.postMessage("fetchUsers");


