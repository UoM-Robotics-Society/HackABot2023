
import requests
response = requests.get(f"http://192.168.4.1")
html_content = response.text
print(html_content)
