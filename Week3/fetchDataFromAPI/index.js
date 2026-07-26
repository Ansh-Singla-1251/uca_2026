const worker=new Worker("worker.js");
worker.onmessage=(event)=>{
  const users=event.data;
  if(!users || users.length===0){
    console.error("No users returned from API");
    return;
  }
  users.forEach(user=>{
    const status=user.active ? "Active":"Inactive";
    console.log(`${user.name}-${status}`);
  });
};
worker.onerror=(error)=>{
  console.error("Worker error:",error.message);
};
worker.postMessage("fetchUsers");
