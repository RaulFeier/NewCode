async function get_api() {
  const api_url_latest =
      'https://awu4j6hku3.execute-api.eu-central-1.amazonaws.com/dev/weather/latest';
  const api_url =
      'https://awu4j6hku3.execute-api.eu-central-1.amazonaws.com/dev/weather/hist?days=5&group=8';

  const response = await fetch(api_url);

  var data = await response.json();
  console.log(typeof (data));
}

function getting_data(data) {
  console.log(data[0].temp.value);
  console.log(data[0].humidity.value);
  console.log(data[0].pressure.value);
  console.log(data[0].wind.value);
}

get_api();  // print them ones and then with the function setinterval it printem
            // them every k milisec after the first print

// const eep = setInterval(get_api, 60000);