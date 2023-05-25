async function get_api() {
  const api_url_latest =
    'https://awu4j6hku3.execute-api.eu-central-1.amazonaws.com/dev/weather/latest';
  const api_url =
    'https://awu4j6hku3.execute-api.eu-central-1.amazonaws.com/dev/weather/hist?days=1&group=1';

  const response = await fetch(api_url);

  var data = await response.json();
  console.log(data);
  // getting_data(data);
}

function getting_data(data) {
  const temps = [];
  const humidity = [];
  const wind = [];
  const pressure = [];

  for (const item of data) {
    switch (item.dataType) {
      case 'temp':
        temps.push(item.value);
        break;
      case 'humidity':
        humidity.push(item.value);
        break;
      case 'wind':
        wind.push(item.value);
        break;
      case 'pressure':
        pressure.push(item.value);
        break;
      default:
        // Handle unrecognized dataType if necessary
        break;
    }
  }

  console.log('Temperatures:', temps);
  console.log('Humidity:', humidity);
  console.log('Wind:', wind);
  console.log('Pressure:', pressure);
}

get_api();  // print them ones and then with the function setinterval it printem
            // them every k milisec after the first print

// const eep = setInterval(get_api, 60000);
