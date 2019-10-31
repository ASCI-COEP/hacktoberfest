import Parsing.readerView

from flask import Flask, request, render_template
from flask_restful import Api

app = Flask(__name__)
api = Api(app)


@app.route('/')
def showpaths():
    paths = "Use path /readerView/"
    return paths


@app.route('/readerView/')
def getreader():
    if 'url' in request.args:
        if 'ret' in request.args:
            if request.args['ret'] == 'json':
                return Parsing.readerView.reader_json(request.args['url'])
            elif request.args['ret'] == 'html':
                value = Parsing.readerView.reader_json(request.args['url'])
                return render_template('reader.html',
                                       title=value['title'],
                                       author=value['author'],
                                       date=value['date'],
                                       text=value['text'],
                                       image=value['image'],
                                       description=value['description'],
                                       url=value['url']
                                       )
            else:
                return 'ret = html or json'
        else:
            return 'Provide return type ret'
    else:
        return 'Provide url in query'


if __name__ == '__main__':
    app.run()
