function NewPromise(execfn){
    this.state="pending";
    this.value=undefined;
    this.handler=[];
    const resolve=(value)=>{
        if(this.state!=="pending")return;
        this.state="fulfilled";
        this.value=value;
        this.handler.forEach(handle);
    };
    const reject=(error)=>{
        if(this.state!=="pending")return;
        this.state="rejected";
        this.value=error;
        this.handler.forEach(handle);
    };
    const handle=(handler)=>{
        if(this.state==="fulfilled"){
            if(handler.onFulfilled){
                try{
                    const result=handler.onFulfilled(this.value);
                    handler.resolve(result);
                }
                catch(err){
                    handler.reject(err);
                }
            }
            else{
                handler.resolve(this.value);
            }
        }
        if(this.state==="rejected"){
            if(handler.onRejected){
                try{
                    const result=handler.onRejected(this.value);
                    handler.resolve(result);
                }
                catch(err){
                    handler.reject(err);
                }
            }
            else{
                handler.reject(this.value);
            }
        }
    };
    this.then=function(onFulfilled,onRejected){
        return new Promise((resolve,reject)=>{
            this.handler.push({
                onFulfilled,onRejected,resolve,reject
            });
            if(this.state!=="pending"){
                handle(this.handler[this.handler.length - 1]);
            }
        });
    };
    this.catch = function (onRejected){
        return this.then(null, onRejected);
    };
    try {
        execfn(resolve, reject);
    } 
    catch (err) {
        reject(err);
    }
}

new NewPromise(resolve => {
    resolve(5);
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log(value);
});
