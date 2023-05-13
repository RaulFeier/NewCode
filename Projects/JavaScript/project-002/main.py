import requests
from datetime import datetime
from zoneinfo import ZoneInfo

crt_rom_dt = datetime.now(tz=ZoneInfo("Europe/Bucharest"))
crt_rom_str = crt_rom_dt.isoformat('T')
# just for testing

# crt_rom_str = "2023-05-05T19:04:11.985270+03:00"
url = "https://awu4j6hku3.execute-api.eu-central-1.amazonaws.com/dev/weather"
data = [
    {
        "time": crt_rom_str,
        "value": 1,
        "dataType": "temp"
    },
    {
        "time": crt_rom_str,
        "value": 27.8,
        "dataType": "humidity"
    },
    {
        "time": crt_rom_str,
        "value": 96.8,
        "dataType": "wind"
    },
    {
        "time": crt_rom_str,
        "value": 180,
        "dataType": "pressure"
    }
]

headers = {'Content-type': 'application/json',
           'x-api-key': '216e0b0d-1c08-4eb6-aa43-0cccddf9bdbf'}

r = requests.post(url, json=data, headers=headers)

print(r.status_code)
print(r.text)
