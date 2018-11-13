

# 解析url
url = 'https://xxx.xxx.xx?name=asdf&age=12&need_phone=true'

def parse_url(url: str):

    index = url.find('?')
    if index == -1:
        print('no params')
        return
    params = {}
    for item in url[index+1:].split('&'):
        k, v = item.split('=')
        params[k]=v
    print(params)


parse_url(url)
parse_url('http://www.666.com')