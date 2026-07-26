self.onmessage=async(event)=>{
  if(event.data==="fetchUsers"){
    try{
      const response=await fetch("https://dummyapi.com/users");
      if(!response.ok){
        throw new Error('Error Status: ${response.status}');
      }
      const users=await response.json();
      self.postMessage(users);
    }
    catch(error){
      self.postMessage([]);
      console.error("Fetch error in worker:",error.message);
    }
  }
}