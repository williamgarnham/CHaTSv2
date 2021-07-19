const express = require('express');
const bodyParser = require('body-parser');

const fs = require('fs');
const path = require('path');

const ip = '0.0.0.0' //Placeholder

const app = express();
app.use(express.static(path.join(__dirname, 'public')));
app.use(bodyParser.urlencoded({ extended: true }));
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'html');

app.use('/will', (req, res, next) => {
  const data = getData();
  console.log(data);
  return res.send(
    `<h1>Temperature: ${data[0].toString()}C Humidity: ${data[1].toString()}%</h1>`
  );
});
app.use('/', (req, res, next) => {
  const data = getData();
  console.log(data);
  res.render(path.join(__dirname, 'views', 'main.html'), {
    temp: data[0],
    hum: data[1],
  });
});

app.listen(3000, ip);

const getData = () => {
  const fileData = fs.readFileSync('./test.txt', 'utf8');
  console.log(fileData);
  return fileData.split(',');
};
