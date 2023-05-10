async function get_api() {
  const api_url = "https://awu4j6hku3.execute-api.eu-central-1.amazonaws.com/dev/weather/latest";
  
  const response = await fetch(api_url);

  var data = await response.json();
  getting_data(data);
}

function getting_data(data) {
  console.log(data.temp.value);
  console.log(data.humidity.value);
  console.log(data.pressure.value);
  console.log(data.wind.value);
}

get_api(); // print them ones and then with the function setinterval it printem them every k milisec after the first print
const eep = setInterval(get_api, 60000);
