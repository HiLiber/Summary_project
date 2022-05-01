const exp = require('express')
const { json } = require('express/lib/response')
const app = exp()

app.use(exp.urlencoded({extended:true}))
app.use(exp.json())

app.set('view engine', 'ejs')

const Net = require('net');

const port = 3000;

const server = new Net.Server();
server.listen(port, function() {
    console.log(`Server listening for connection requests on socket localhost:${port}.`);
});

server.on('connection', function(socket) {
    console.log('A new connection has been established.');

    socket.write('Hello, client.');

    socket.on('data', function(chunk) {
        console.log(`Data received from client: ${chunk.toString()}.`);
        console.log(chunk.toJSON());
    });
   
    socket.on('close', function() {
        console.log('Closing connection with the client');
    });
   
    socket.on('error', function(err) {
        console.log(`Error: ${err}`);
    });
});

app.get('/',(req,res)=>{
    res.send('hhhhhhhhhh')
})

app.post('/sendMessage', (req, res) => {
    const data = req.body;
    res.render('page', {data:data})
// res.send('hello')

})