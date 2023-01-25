# HTTP RFC

From https://www.rfc-editor.org/rfc/rfc9112.html

## Introduction

- HTTP is stateless, application-level, request/response protocol

## Message

### Format

- an HTTP/1.1 message basic structure

```
  HTTP-message   = start-line CRLF
                   *( field-line CRLF )
                   CRLF
                   [ message-body ]
```

- Request (client>server) or response (server>client)
  - Differences are:
    - start-line (`reuqest-line` for requests vs `status-line` for responsts)
    - algorithm to determine length of message body
- Usually, servers are implement to only expect a request; clients to only expect a response

### Parsing

- To parse an HTTP message:
  - read start-line into structure
  - read each header line into hash table by field name
  - figures out if message body is expected by parsed data
    - If required, reads it as stream until:
      - amount of octets equal to body length is read
      - connection is closed
- Message must be parsed in an encoding that is superset of US-ASCII
- A server that is expecting to receive/parse a request-line should ignore at least 1 CLFR received prior to the request-line
- When a server receives a sequence of octets that doesn't match HTTP-message grammar, it should return 400 (Bad Request)

### HTTP version

- Version of HTTP/1.x message is indicated by HTTP-version field in `start-line`

```
  HTTP-version  = HTTP-name "/" DIGIT "." DIGIT
  HTTP-name     = %s"HTTP"
```

### Request line

- Begins with method token + single space + request-rarget + single space + protocol version

```
  request-line   = method SP request-target SP HTTP-version
```

- Protocol doesn't establish a limit on length of request-line
- It is recommended to support at least 8000 octets of request-line

### Method

- Indicates the method to be performed

```
  method         = token
```

### Request target

- Identifies target resource on which to apply request
- Four formats depending on method being used or whether request is proxy

```
  request-target = origin-form
                 / absolute-form
                 / authority-form
                 / asterisk-form
```

- No whitespace allowed

#### Origin form

- Most common form of request-target

```
  origin-form    = absolute-path [ "?" query ]
```

- If path is empty, client must send `/`

- Example:

```
GET /where?q=now HTTP/1.1
Host: www.example.org
```

#### Absolute form
- When making request to a proxy
```
  absolute-form  = absolute-URI
```
