const exp = require('express')
const app = exp()
app.listen('3000', ()=>console.log('app listening in http://localhost:3000'))
app.use(exp.urlencoded({extended:true}))
app.use(exp.json())

app.set('view engine', 'ejs')

app.get('/',(req,res)=>{
    res.send('hhhhhhhhhh')
})

app.post('/sendMessage', (req, res) => {
    const data = req.body;
    res.render('page', {data:data})
// res.send('hello')

})