// { name: string, size: string, price: number, quantity: number }

let Cart={
    items:[],

    addItems: function(obj){
        let flag=0
        for( let i=0; i<this.items.length; i++){
            if(this.items[i].name===obj.name){
                this.items[i].quantity++;
                flag=1;
                break;
            }
        }
        if(flag===0){
            this.items.push(obj)
        }
    },

    displayItems: function(){
        console.log("\nThe Items in your Cart are: ")
        this.items.map((element)=>{
            console.log(element)
        })
    },

    removeItems: function(name, quantity){

        let tempQuantity=0;
        let flag=0

        for( let i=0; i<this.items.length; i++ ){
            if(this.items[i].name===name){
                this.items[i].quantity=this.items[i].quantity-quantity;
                tempQuantity=this.items[i].quantity
                flag=1;
                break;
            }
        }
        if(tempQuantity<=0){
            this.items=this.items.filter((element)=> name!== element.name)
        }
        if (flag===0)
        {
            console.log("Object not found")
        }
    },

    calculateTotal: function() {
        
        for(let i = 0; i < this.items.length; i++) {
            console.log("The Price of the " + this.items[i].name + " is: " + (this.items[i].quantity * this.items[i].price));
        }
    
        
        let total = this.items.reduce((sum, element) => {
            return sum + (element.price * element.quantity);
        }, 0); 
    
        console.log("Total price: ", total);
    }
    

}

obj1={
    name: "lipgloss",
    size: "small",
    price: 5,
    quantity: 1
}

obj2={
    name: "teddy bear",
    size: "large",
    price: 10,
    quantity: 1
}

obj3={
    name: "perfume",
    size: "medium",
    price: 20,
    quantity: 1
}

Cart.addItems(obj1)
Cart.addItems(obj1)
Cart.addItems(obj2)
Cart.displayItems()
Cart.calculateTotal()
Cart.addItems(obj1)
Cart.displayItems()
Cart.calculateTotal()
Cart.removeItems("lipgloss",3)
Cart.displayItems()
Cart.calculateTotal()
Cart.removeItems("lipgloss",1)