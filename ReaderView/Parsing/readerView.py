from newspaper import Article


def reader_json(url):
    article = Article(url)
    article.download()
    article.parse()
    title = article.title
    date_time = article.publish_date
    if date_time is not None:
        date = date_time.strftime("%d-%b-%Y")
    else:
        date = ""
    desc = article.meta_description if article.meta_description is not None else ""
    text = article.text if article.text is not None else ""
    author = article.authors[0] if len(article.authors) > 0 else ""
    image = article.top_image if article.top_image is not None else ""
    reader = {
        "title": title,
        "author": author,
        "date": date,
        "text": text,
        "image": image,
        "description": desc,
        "url": url
    }
    return reader