# Eiffel protocol publisher for test results
# Requires: pip install pika
import pika
import json
import sys
import os

def publish_to_rabbitmq(message, queue='eiffel_test_results'):
    connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
    channel = connection.channel()
    channel.queue_declare(queue=queue, durable=True)
    channel.basic_publish(exchange='', routing_key=queue, body=message)
    connection.close()

def main():
    if len(sys.argv) < 2:
        print("Usage: python publish_eiffel.py <test_results_file>")
        sys.exit(1)
    test_results_file = sys.argv[1]
    if not os.path.exists(test_results_file):
        print(f"File not found: {test_results_file}")
        sys.exit(1)
    with open(test_results_file, 'r') as f:
        test_output = f.read()
    # Example Eiffel event (simplified)
    eiffel_event = {
        "meta": {
            "type": "EiffelTestCaseFinishedEvent",
            "version": "3.0.0"
        },
        "data": {
            "outcome": "SUCCESS" if '100% tests passed' in test_output else "FAILURE",
            "test_output": test_output
        }
    }
    message = json.dumps(eiffel_event)
    publish_to_rabbitmq(message)
    print("Published Eiffel event to RabbitMQ.")

if __name__ == "__main__":
    main()
