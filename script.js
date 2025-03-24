// JavaScript code to manage the queue system
const clientForm = document.getElementById("clientForm");
const clientTable = document.getElementById("clientTable").querySelector("tbody");

const clients = []; // Array to hold the clients (queue)

// Function to calculate dates
function getDateOffset(offsetYears) {
    const date = new Date();
    date.setFullYear(date.getFullYear() + offsetYears);
    return date.toISOString().split("T")[0]; // Return YYYY-MM-DD
}

// Function to add client to the queue
clientForm.addEventListener("submit", (e) => {
    e.preventDefault();

    const name = document.getElementById("name").value.trim();
    const policy = document.getElementById("policy").value;
    const nominee = document.getElementById("nominee").value.trim();

    const startDate = getDateOffset(0); // Today
    const maturityDate = getDateOffset(10); // 10 years from today

    // Add client to the queue
    const newClient = { name, policy, startDate, maturityDate, nominee };
    clients.push(newClient);
    displayClients();

    // Reset the form
    clientForm.reset();
});

// Function to display clients in the table
function displayClients() {
    clientTable.innerHTML = ""; // Clear table

    clients.forEach((client, index) => {
        const row = document.createElement("tr");

        row.innerHTML = `
            <td>${client.name}</td>
            <td>${client.policy}</td>
            <td>${client.startDate}</td>
            <td>${client.maturityDate}</td>
            <td>${client.nominee}</td>
            <td><button class="remove-btn" onclick="removeClient(${index})">Remove</button></td>
        `;

        clientTable.appendChild(row);
    });
}

// Function to remove the first client in the queue
function removeClient(index) {
    clients.splice(index, 1); // Remove the client at the index
    displayClients(); // Refresh the table
}
