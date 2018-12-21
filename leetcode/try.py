import requests

def retry(count=3):
    def inner_retry(func):
        def wrapped(*args, **kwargs):
            for i in range(count):
                try:
                    func(*args, **kwargs)
                except Exception as err:
                    print(f"{i} try qith {err.args}")
        return wrapped
    return inner_retry

@retry(4)
def get(url: str):
    requests.get(url)


get('http://localhost')