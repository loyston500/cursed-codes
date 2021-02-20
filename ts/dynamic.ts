const a: any = 35;
const b: any = 34;
console.log(a + b);

const foo: any = "foo";
const bar: any = "bar";
console.log(foo + bar);

function sum(a: any, b: any): any{
    return a + b;
}
console.log(sum(400, 20));

class Person{
    public name: any;
    public age: any;
    public gender: any;
    constructor(name: any, age: any, gender: any){
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
}
const person: any = new Person("Mia", 42.0, "female");
console.log(`${person.name} is a ${person.age} years old ${person.gender}`);