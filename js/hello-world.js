text = [ 72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100]
str = []
text.forEach(letter => {
	str.push(String.fromCharCode(letter))
})
str = str.join('')
console.log(str)
